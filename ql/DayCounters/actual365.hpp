
/*
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file actual365.hpp
    \brief act/365 day counter
*/

#ifndef quantlib_actual365_day_counter_h
#define quantlib_actual365_day_counter_h

#include <ql/daycounter.hpp>

namespace QuantLib {

    //! Actual/365 day count convention
    /*! \ingroup daycounters */
    class Actual365 : public DayCounter {
      private:
        class Impl : public DayCounter::Impl {
          public:
            std::string name() const { return std::string("act/365"); }
            BigInteger dayCount(const Date& d1, const Date& d2) const {
                return (d2-d1); 
            }
            Time yearFraction(const Date& d1, const Date& d2,
                              const Date&, const Date&) const {
                return dayCount(d1,d2)/365.0;
            }
        };
      public:
        Actual365()
        : DayCounter(boost::shared_ptr<DayCounter::Impl>(
                                                      new Actual365::Impl)) {}
    };

}


#endif
