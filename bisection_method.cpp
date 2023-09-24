#include <iostream>
#include <cmath>
#include <iomanip>


double f(double x){
  double f_x {};
  f_x = (x * x * x) - (4 * x) - 9;
  return f_x;
}

int main(){
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(5);
  double a {}, b {}, c{};
  double eps {}; // degree of accuracy
  double f_a {}, f_b {}, f_c {};

  bool not_valid_bounds = true;

  while (not_valid_bounds){
    std::cout << "Enter value for a: " << std::endl;
    std::cin >> a;
    std::cout << "Enter value for b: " << std::endl;
    std::cin >> b;

    f_a = f(a);
    f_b = f(b);

    if (f_a * f_b < 0){
      std::cout << "Valid bounds for a and b." << std::endl;
      not_valid_bounds = false;
    }else{
      std::cout << "Please enter different values for a and b." << std::endl;
    }
  }

  std::cout << "Enter accuracy value (epsilon): " << std::endl;
  std::cin >> eps;

  int n_iter{};

  std::cout << "NO. iterations:"<<std::setw(14)<<"a"<<std::setw(18)<<"b"<<std::setw(18)<<"c"
    <<std::setw(18)<<"f(a)"<<std::setw(18)<<"f(b)"<<std::setw(18)<<"|f(a)-f(b)|"<<std::setw(18)<<std::endl;
  while (std::abs(f_a - f_b ) >= eps){
    c = (a + b) / 2;
    f_a = f(a);
    f_b = f(b);
    f_c = f(c);
    n_iter++;
    std::cout << n_iter <<std::setw(14)<<a<<std::setw(18)<<b<<std::setw(18)<<c
      <<std::setw(18)<<f_a<<std::setw(18)<<f_b<<std::setw(18)<< std::abs(f_a-f_b) <<std::setw(18)<<std::endl;
    if (f_c==0){
      std::cout <<"Root = " <<c <<std::endl;
      return 0;
    }

    if (f_a*f_c > 0){
      // if fa*fc >0 then there is no root between a & c, so set a to c
      a = c;
    }
    else if (f_a*f_c < 0){
      // a root exists between a and c, so set b to c
      b = c;
    }
  }

  std::cout <<"Root = " <<c <<std::endl;

  return 0;
}
