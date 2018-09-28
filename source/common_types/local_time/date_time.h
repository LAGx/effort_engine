#include <string>
#include <chrono>


namespace eff{
namespace common_types{

/*!
@brief functor, that return time of local machine
@warning low performance.
@example
DateTime loct;
loct(DateTime::TimeType::Year); //will return 2018
*/
class DateTime{
public:

    enum class TimeType: char{
        Second = 0, //< seconds [0, 60]
        Minute,     //< minutes [0, 59]
        Hour,       //< hours   [0, 23]
        Day,        //< days    [1, 31]
        Month,      //< month   [1, 12]
        Year        //< year    [in xxxx format]
    };

    /*!
    @param[in] timeType {what to return}
    @return time in normal format
    */
    unsigned int operator()(TimeType timeType);

    /*!
    @brief tools for more efficient using class.
    use update() than use then get_core()
    */
    struct{
        void update();              //< use before get_core()
        std::tm& get_core() const;  //< core struct

        DateTime& parent;
    }high_performance_tool = {*this};

private:

    std::time_t rawtime;
    std::tm* timeinfo;
};


};
};
