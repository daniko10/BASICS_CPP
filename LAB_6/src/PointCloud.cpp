#include "PointCloud.h"

using std::cout;
using std::endl;

int Point3D::DISPLAY_PRESITION = 0;

void Point3D::displayCoordinates() const {
    cout<<"("<<my_point[0]<<", "<<my_point[1]<<", "<<my_point[2]<<")"<<endl;
}

Point3D* VPointCloud::getCopyPoint(int index) {
    my_vector[index]->to_alloc = false;
    return VPointCloud::my_vector[index];
}

void VPointCloud::addPoint(Point3D* ptr_obj) {
    if(!ptr_obj->to_alloc)
        my_vector.push_back(new Point3D(ptr_obj->my_point));
    else
        my_vector.push_back(ptr_obj);
    n++;
    ptr_obj->to_alloc = true;
}

void VPointCloud::addPoint(std::array<double, 3> my_list_point) {
    my_vector.push_back(new Point3D(my_list_point));
    n++;
}

void VPointCloud::add(VPointCloud& obj_to_add) {
    int t = obj_to_add.n;
    for(int i=0; i<t; i++) {
        my_vector.push_back(new Point3D(obj_to_add.my_vector[i]->my_point));
        n++;
    }
}

void VPointCloud::displayPoints() const {
    for(int i=0; i<n; i++) {
        cout<<"(";
        for(int j=0; j<3; j++) {
            cout<<my_vector[i]->my_point[j];
            if(j!=2)
                cout<<", ";
        }
        cout<<")"<<endl;
    }
}

VPointCloud::~VPointCloud() {
    if(n>0) {
        for(int i=0; i<n; i++)
            delete my_vector[i];
        my_vector.clear();
    }
}