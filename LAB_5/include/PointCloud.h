#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <vector>

class Point3D {
    public:
        Point3D(): my_point({0,0,0}) {};
        Point3D(std::array<double, 3> list_x_y_z): my_point(list_x_y_z) {};
        void displayCoordinates() const;

        friend class APointCloud;
        friend class VPointCloud;
    private:
        std::array<double, 3> my_point;
};

class APointCloud {
    public:
        ~APointCloud();
        APointCloud() = default;
        Point3D geoCentre();
        void addPoint(Point3D);
        void displayPoints() const;

        friend class VPointCloud;
    private:
        Point3D ** ptr_my_point = nullptr;
        int size_A = 0;
};

class VPointCloud {
    public:
        ~VPointCloud();
        VPointCloud() = default;
        void addPoint(Point3D);
        void add(APointCloud&);
        int count() const;
        Point3D geoCentre();
    private:
        std::vector<Point3D*> my_vector;
        int n=0;
};

#endif