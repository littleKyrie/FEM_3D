#include <dV_spring_particle_particle_dq.h>

void dV_spring_particle_particle_dq(
        Eigen::Ref<Eigen::Vector6d> f,
        Eigen::Ref<const Eigen::Vector3d> q0,
        Eigen::Ref<const Eigen::Vector3d> q1,
        double l0, double stiffness) {

    /*
    Eigen::Vector3d direction = (q0 - q1) / (q0 - q1).norm();
    Eigen::Vector3d reverseDir = (q1 - q0) / (q1 - q0).norm();
    Eigen::Vector3d f0 = - stiffness * ((q0 - q1).norm() - l0) * direction;
    Eigen::Vector3d f1 = - stiffness * ((q1 - q0).norm() - l0) * reverseDir;
    f << f0,
         f1;
    */

    Eigen::Vector6d q;
    q << q0[0] - q1[0],
            q0[1] - q1[1],
            q0[2] - q1[2],
            q1[0] - q0[0],
            q1[1] - q0[1],
            q1[2] - q0[2];
    //q << q0 - q1,
    //    q1 - q0;
    double l = (q0 - q1).norm();
    f = stiffness * (l - l0) * q / l;
}