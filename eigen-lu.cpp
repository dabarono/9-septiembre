#include <iostream>
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <cmath>


double solvesystem(const int & size);

int main(int argc, char ** argv)
{
  const int N = atoi(argv[1]); // Repetitions
  const int M = atoi(argv[2]); // Matrix size
  //const int s = atoi(argv[3]); // seed

  double sum=0;
  double sum2=0;
  double time=0;
  int rep;
  
  for (rep = 0; rep < N; ++rep){
    srand(rep +1);
    time=solvesystem(M);
    sum=sum+time;
    sum2=sum2+time*time;
  }
  double mean=sum/N;
  double sigman=sqrt(N*((sum2/N)-mean*mean)/(N-1));
  std::cout<<M*M<<" "<<mean<<" "<<sigman<<std::endl;
}

double solvesystem(const int & size)
{
  std::chrono::time_point<std::chrono::system_clock> start,end;//se definen dos variables de forma chrono
  Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
  Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);
  start=std::chrono::system_clock::now();//mide el tiempo ahora
  Eigen::MatrixXd x = A.fullPivLu().solve(b);
  end=std::chrono::system_clock::now();//mide el tiempo ahora
  std::chrono::duration<double> elapsed_seconds = end-start;//defino otro tipo de variable tamperoal
  //std::cout<< elapsed_seconds.count()<<std::endl;//imprimo la ultima variable
  //std::cout<<A<<std::endl;
  //std::cout<<b<<std::endl;
  //std::cout<<x<<std::endl;
  //double relative_error = (A*x - b).norm() / b.norm(); // norm() is L2 norm
  //std::cout << "The relative error is:\n" << relative_error << std::endl;
  return elapsed_seconds.count();
}
