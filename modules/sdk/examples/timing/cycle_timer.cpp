#include <iostream>
#include <boost/config.hpp>
#include <nt2/include/timing.hpp>

using namespace std;

int main()
{
  int wait;
  nt2::details::cycles_t d;

  cout << "How many seconds do you want to wait ? ";
  cin >> wait;
  {
    nt2::time::cycle_timer s(d);

    #if defined(BOOST_MSVC)
    Sleep(1000*wait);
    #else
    sleep(wait);
    #endif
  }
}


