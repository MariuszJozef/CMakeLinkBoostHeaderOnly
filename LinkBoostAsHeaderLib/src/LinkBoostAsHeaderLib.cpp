#include <iostream>
#include <boost/rational.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "LinkBoostAsHeaderLib.hpp"

namespace BoostEx
{

void BoostRationalEx1()
{
    boost::rational<int> rTwoThirds(2, 3);
    boost::rational<int> rThreeFourths(3, 4);

    std::cout << rTwoThirds << " + " << rThreeFourths 
        << " = " << rTwoThirds + rThreeFourths << "\n";

    boost::rational<int> r1_3(1, 3);
    boost::rational<int> r1_6(1, 6);

    std::cout << r1_3 << " + " << r1_6 << " = " << r1_3 + r1_6 << "\n";

    std::cout << boost::rational<int>(5, 9) << "\n";
}

void BoostDateEx1()
{
    boost::gregorian::date someDate {1687, 8, 3};
    std::cout << "someDate = " << someDate << "\n";

    someDate += boost::gregorian::years(3);
    someDate += boost::gregorian::months(-5);
    someDate -= boost::gregorian::days(8);
    std::cout << "someDate = " << someDate << "\n";
}

void BoostTimeEx1()
{
    boost::posix_time::time_duration someTime {8, 9, 11};
    std::cout << "someTime = " << someTime << "\n";

    someTime += boost::posix_time::hours(2);
    someTime += boost::posix_time::minutes(-12);
    someTime -= boost::posix_time::seconds(17);
    std::cout << "someTime = " << someTime << "\n";

    someTime = boost::posix_time::time_duration(
        boost::posix_time::hours(13)
        + boost::posix_time::minutes(-14)
        - boost::posix_time::seconds(15));
    std::cout << "someTime = " << someTime << "\n";
}

} // ~namespace BoostEx
