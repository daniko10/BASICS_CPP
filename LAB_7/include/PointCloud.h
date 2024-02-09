#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <array>
#include <cmath>
#include <cstring>
#include <vector>

class Point3D {
    friend class VPointCloud;

    public:
        Point3D(std::array<double, 3> ctr_my_point): my_point(ctr_my_point) {};
        Point3D(double x): my_point({x,x,x}) {};
        void displayCoordinates() const;

        explicit operator double() {
            return sqrt(my_point[0]*my_point[0]
                        + my_point[1]*my_point[1]
                        + my_point[2]*my_point[2]    
            );
        }
        static std::string to_string(const Point3D& obj) {
            return (std::string)((Point3D)(obj));
        }
        operator std::string() {
            std::string str = "(" + std::to_string(my_point[0]) + ", "
                                  + std::to_string(my_point[1]) + ", "
                                  + std::to_string(my_point[2]);
            return str;
        }

        operator std::string() const{
            std::string str = "(" + std::to_string(my_point[0]) + ", "
                                  + std::to_string(my_point[1]) + ", "
                                  + std::to_string(my_point[2]);
            return str;
        }

    private:
        std::array<double, 3> my_point;
};

class VPointCloud {
    public:
        ~VPointCloud();
        VPointCloud() = default;
        VPointCloud(VPointCloud&& );
        void addPoint(Point3D*);
        void addPoint();
        void add(VPointCloud&);
        void displayPoints() const;

    private:
        std::vector<Point3D*> my_vector;
        int n=0;
};

#endif