#pragma once
#include <string>
#include <chrono>


namespace eff{
namespace common_types{



/*!
 @brief functor, that return time of local machine

 @warning low performance.

 <B>example:</B>
 @code
 DateTime loct;
 cout << loct(DateTime::TimeType::Year); //will return 2018
 @endcode
 */
class DateTime{
public:


    /// time type
    enum class TimeType: char{
        Second = 0, ///< seconds [0, 60]
        Minute,     ///< minutes [0, 59]
        Hour,       ///< hours   [0, 23]
        Day,        ///< days    [1, 31]
        Month,      ///< month   [1, 12]
        Year        ///< year    [in xxxx format]
    };


    /*!
    @brief use for get time

    @param[in] timeType what to return

    @return time in normal format
    */
    unsigned int operator()(TimeType timeType);


    /*!
    @brief tools for more efficient class using.

    <B>example:</B>
    @code
    data.high_performance_tool.update();
    cout << "hours: " << data.high_performance_tool.get_core().tm_hour << endl;
    cout << "minutes: " << data.high_performance_tool.get_core().tm_min << endl;
    @endcode
    */
    struct{
        void update();              ///< use before get_core()
        std::tm& get_core() const;  ///< core struct

        /// @private
        DateTime& parent;
    }high_performance_tool = {*this};

private:

    std::time_t rawtime;
    std::tm timeinfo;
};


};
};
