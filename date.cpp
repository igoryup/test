#include <tuple>
const int DEFAULT_DAY = 1;
const int DEFAULT_MONTH = 1;
const int DEFAULT_YEAR = 1970;
const int DAYS_WO_FEB = 337;
const int FEB = 2;

class Date
{
private:
    // int day = DEFAULT_DAY;
    // int month = DEFAULT_MONTH;
    // int year = DEFAULT_YEAR;
    int totalDaysVal = 0;

    int GetDaysInMonth(int month, int year) const
    {
        switch (month)
        {
        case 2:
            if ((!(year % 4) && (year % 100)) || !(year % 400))
            {
                return 29;
            }
            return 28;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return 30;
        }
    }
    int GetDaysInYear(int year) const
    {
        return DAYS_WO_FEB + GetDaysInMonth(FEB, year);
    }
    int GetDaysToThisDateOfYear(int day, int month, int year) const
    {
        int days = 0;
        for (int i = 1; i != month; ++i)
        {
            days += GetDaysInMonth(i, year);
        }
        return days + day - DEFAULT_DAY;
    }
    int TotalDays(int day, int month, int year) const
    {
        int days = 0;
        for (int i = DEFAULT_YEAR; i != year; ++i)
        {
            days += GetDaysInYear(i);
        }
        days += GetDaysToThisDateOfYear(day, month, year);
        return days;
    }
    void DateToDays(int days)
    {
        totalDaysVal = days;
    }
    std::tuple<int, int, int> DaysToDate(int days) const
    {
        int month = DEFAULT_MONTH;
        int year = DEFAULT_YEAR;
        int day = days + DEFAULT_DAY;

        while (day > GetDaysInYear(year))
        {
            day -= GetDaysInYear(year);
            ++year;
        }

        while (day > GetDaysInMonth(month, year))
        {
            day -= GetDaysInMonth(month, year);
            ++month;
        }

        return {day, month, year};
    }
    bool IsCorrectDate(int d, int m, int y) const
    {
        return m <= 12 && m >= 1 && d <= GetDaysInMonth(m, y) && d > 0;
    }

public:
    Date(int d, int m, int y)
    {

        if (!IsCorrectDate(d, m, y))
        {
            totalDaysVal = 0;
        }
        else
        {
            totalDaysVal = TotalDays(d, m, y);
        }
    }

    int GetDay() const
    {
        return std::get<0>(DaysToDate(totalDaysVal));
    }

    int GetMonth() const
    {
        return std::get<1>(DaysToDate(totalDaysVal));
    }

    int GetYear() const
    {
        return std::get<2>(DaysToDate(totalDaysVal));
    }

    int GetDays() const
    {
        return TotalDays(GetDay(), GetMonth(), GetYear());
    }

    Date operator+(int d) const
    {
        Date res(*this);
        const int buf = GetDays();
        res.DateToDays(buf + d);
        return *this;
    }

    Date operator-(int d) const
    {
        Date res(*this);
        const int buf = GetDays();
        res.DateToDays(buf - d);
        return res;
    }

    int operator-(const Date &other) const
    {
        return GetDays() - other.GetDays();
    }
};

int main()
{
    Date d1(0, 0, 0);
    Date d2(2, 1, 1970);
    int lol = d1.GetDays();
    lol = d2.GetDays();

    d1 = d1 + 31;
    int day = d1.GetDay();
    int month = d1.GetMonth();
    int year = d1.GetYear();
    d1 = d1 - 1;
    day = d1.GetDay();
    month = d1.GetMonth();
    year = d1.GetYear();
    lol = d1 - d2;
    day = d1.GetDay();
    month = d1.GetMonth();
    year = d1.GetYear();
    lol = 0;
}