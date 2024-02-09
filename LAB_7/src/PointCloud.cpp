#include "PointCloud.h"

using std::cout;
using std::endl;

void Point3D::displayCoordinates() const {
    cout<<"("<<my_point[0]<<", "<<my_point[1]<<", "<<my_point[2]<<")"<<endl;
}

void VPointCloud::addPoint(Point3D* ptr_to_point) {
    my_vector.push_back(ptr_to_point);
    n++;
}
void VPointCloud::addPoint() {
    my_vector.push_back(new Point3D({0,0,0}));
    n++;
}

void VPointCloud::displayPoints() const {
    for(int i=0; i<n;i++) 
        cout<<"("<<my_vector[i]->my_point[0]<<", "<<my_vector[i]->my_point[1]<<", "<<my_vector[i]->my_point[2]<<")"<<endl;
}

void VPointCloud::add(VPointCloud& obj) {
    if(this == &obj)
        return;
    
    for(int i=0; i<n; i++)
        my_vector.push_back(new Point3D(obj.my_vector[i]->my_point));
}

VPointCloud::VPointCloud(VPointCloud&& obj): my_vector(std::move(obj.my_vector)), n(std::move(obj.n)) {
    obj.n = 0;
}

VPointCloud::~VPointCloud() {
    for(int i=0; i<n; i++)
        delete my_vector[i];
    my_vector.clear();
}
