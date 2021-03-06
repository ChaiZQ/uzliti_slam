// Copyright (c) 2014, Institute of Computer Engineering (ITI), Universität zu Lübeck
// Jan Frost, Jan Helge Klüssendorff
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice, this
//    list of conditions and the following disclaimer in the documentation and/or
//    other materials provided with the distribution.
// 3. Neither the name of the copyright holder nor the names of its contributors may
//    be used to endorse or promote products derived from this software without
//    specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef CLOUD_TRANSFORMATION_ESTIMATION_H
#define CLOUD_TRANSFORMATION_ESTIMATION_H

#include <graph_slam_tools/transformation/transformation_estimator.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

class CloudTransformationEstimator : public TransformationEstimator
{
public:
    CloudTransformationEstimator(boost::function<void (SlamEdge)> callback);

    bool estimateEdgeImpl(SlamNode &from, SlamNode &to, SlamEdge &edge);

    std::map<std::string, Eigen::Isometry3d, std::less<std::string>, Eigen::aligned_allocator<std::pair<const std::string, Eigen::Isometry3d> > > sensor_transforms_;

protected:
    void transformPointCloudInPlace(Eigen::Transform<double,3,Eigen::Affine,Eigen::ColMajor> Tr, pcl::PointCloud<pcl::PointXYZRGBA> &pc);
    double estimateTransform(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &from, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &to, Eigen::Affine3d &T);

    pcl::visualization::CloudViewer viewer;
};

#endif
