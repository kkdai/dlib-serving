#ifndef SHAPE_DETECTION_SERVICE_H
#define SHAPE_DETECTION_SERVICE_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

#include <grpc/grpc.h>
#include <grpcpp/server_context.h>

#include <dlib/config.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing.h>

#include "jpeg_loader.h"
#include "inference.pb.h"
#include "inference.grpc.pb.h"
#include "shape_detection_service.h"

using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::Status;

using inference::ShapeDetection;
using inference::DetectionResponse;
using inference::DetectionRequest;

class DlibShapeDetectionService final : public ShapeDetection::Service {
  public:
    explicit DlibShapeDetectionService(const std::string& model_file) {
      model_file_ = model_file;
      sp_ = dlib::shape_predictor();
      dlib::deserialize(model_file_) >> sp_;
    }

    Status DetectShape(ServerContext* context, DetectionRequest *request, DetectionResponse *response);

  private:
    std::string model_file_;
    dlib::shape_predictor sp_;
};

#endif
