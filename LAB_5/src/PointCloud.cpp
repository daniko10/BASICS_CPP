#include "PointCloud.h"

using std::cout;
using std::endl;

void Point3D::displayCoordinates() const {
    cout<<"("<<my_point[0]<<", "<<my_point[1]<<", "<<my_point[2]<<")";
}

Point3D APointCloud::geoCentre() {
    Point3D temp;
    for(int i=0; i<size_A; i++) {
        temp.my_point[0] += ptr_my_point[i]->my_point[0];
        temp.my_point[1] += ptr_my_point[i]->my_point[1];
        temp.my_point[2] += ptr_my_point[i]->my_point[2];
    }
    temp.my_point[0] /= size_A;
    temp.my_point[1] /= size_A;
    temp.my_point[2] /= size_A;

    return temp;
}

void APointCloud::displayPoints() const {
    for(int i=0; i<size_A; i++) {
        cout<<"(";
        for(int j=0; j<3; j++) {
            cout<<ptr_my_point[i]->my_point[j];
            if(j!=2)
                cout<<", ";
        }
        cout<<")"<<endl;
    }
}

void APointCloud::addPoint(Point3D obj) {
    size_A++;
    Point3D** temp = new Point3D*[size_A];

    for(int i=0; i<size_A-1; i++) {
        temp[i] = ptr_my_point[i];
    }
    if(ptr_my_point)
        delete [] ptr_my_point;
    temp[size_A-1] = new Point3D(obj.my_point);
    ptr_my_point = temp;

}

void VPointCloud::addPoint(Point3D obj) {
    my_vector.push_back(new Point3D(obj.my_point));
    n++;
}

void VPointCloud::add(APointCloud& obj) {
    for(int i=0; i<obj.size_A; i++) {
        my_vector.push_back(new Point3D(obj.ptr_my_point[i]->my_point));
        n++;
    }
}

int VPointCloud::count() const {
    return n;
}

Point3D VPointCloud::geoCentre() {
    Point3D temp;
    for(int i=0;i<n;i++) {
        temp.my_point[0] += my_vector[i]->my_point[0];
        temp.my_point[1] += my_vector[i]->my_point[1];
        temp.my_point[2] += my_vector[i]->my_point[2];
    }

    temp.my_point[0] /= n;
    temp.my_point[1] /= n;
    temp.my_point[2] /= n;

    return temp;
}

VPointCloud::~VPointCloud() {
    for(int i=0; i<n; i++)
        delete my_vector[i];
    my_vector.clear();
}

APointCloud::~APointCloud() {
    for(int i=0; i<size_A; i++) {
        delete ptr_my_point[i];
    }
    delete [] ptr_my_point;
}