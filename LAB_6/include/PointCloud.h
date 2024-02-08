#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <vector>

class Point3D {
    public:
        Point3D(): my_point({0,0,0}) {};
        Point3D(std::array<double, 3> my_x_y_z): my_point(my_x_y_z) {};
        Point3D(double x): my_point({x,x,x}) {};
        void displayCoordinates() const;

        static int DISPLAY_PRESITION;
        friend class VPointCloud;

    private:
        std::array<double, 3> my_point;
        bool to_alloc = true;
};

class VPointCloud {
    public:
        ~VPointCloud();
        VPointCloud() = default;
        VPointCloud(VPointCloud&& obj): my_vector(std::move(obj.my_vector)), n(std::move(obj.n)) {obj.n = 0;}
        Point3D* getCopyPoint(int);
        void addPoint(Point3D*);
        void addPoint(std::array<double, 3>);
        void add(VPointCloud&);
        void displayPoints() const;
    
    private:
        std::vector<Point3D*> my_vector;
        int n=0;
};

#endif