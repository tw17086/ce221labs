using namespace std;

#include <iostream>
#include <iomanip>
#include "Time.h"

Time::Time()
{ hour = min = sec = 0;
}

Time::Time(int h, int m, int s)
{ setTime(h, m, s);
}

void Time::setTime(int h, int m, int s)
{ hour = (h>=0 && h<24) ? h : 0;
  min = (m>=0 && m<60) ? m : 0;
  sec = (s>=0 && s<60) ? s : 0;
}

Time& Time::operator+=(unsigned int n)
{ sec += n;
  if (sec >= 60)
  { min += sec/60;
    sec %= 60;
    if (min >=60)
    { hour = (hour + min/60) % 24;
      min %= 60;
    }
  }
  return *this;
}

Time Time::operator+(unsigned int n) const
{ Time tCopy(*this);
  tCopy += n;
  return tCopy;
}

Time& Time::operator++()        // prefix version
{ *this += 1;
  return *this;
}

Time Time::operator++(int n)    // postfix version
{ Time tCopy(*this);
  *this += 1;
  return tCopy;
}

// new member functions

bool Time::operator<(const Time& t) const
{
	if (hour < t.hour){ return true; }
	else
	{
		if (min < t.min) { return true; }
		else
		{
			if (sec < t.sec) { return true; }
		}
	}
	return false;
}

bool Time::operator<=(const Time& t) const
{
	return (*this < t) || (*this == t);
}

bool Time::operator==(const Time& t) const
{
	if (hour == t.hour){
		if (min == t.min) {
			if (sec == t.sec) { return true; }
		}
	}
	return false;
}

Time Time::operator-(unsigned int i) const
{	Time tCopy(*this);
  	tCopy -= i;
  	return tCopy;
}

Time& Time::operator-=(unsigned int i)
{	sec -= i;
	min = (min + sec)/60;
	cout << "min " << min << endl;
	if (sec%=60 != 0) sec += 60;
	hour = hour + min/60;
	cout << "hour " << hour << endl;
	if (min%=60 != 0) min += 60;
	hour %= 24;
	return *this;
}

Time& Time::operator--()// prefix version
{

}

Time Time::operator--(int)// postfix version
{

}


ostream& operator<<(ostream &o, const Time &t)
{ o << setfill('0') << setw(2) <<  t.hour << ':' << setw(2) << t.min << ':' << setw(2) << t.sec;
  return o;
}

//new friend functions

bool operator>(const Time& t1, const Time& t2)
{
	return !(t1 <= t2);
}

bool operator>=(const Time& t1, const Time& t2)
{
	return (t1 > t2) || (t1 == t2);
}
bool operator!=(const Time&, const Time&){
}
unsigned int operator%(const Time&, const Time&){
  // t1%t2 should mean the elapsed time in sec from t1 to t2
  // e.g. if t1 is 10.45am and t2 is 11.55am t1%t2 would be 4200 (i.e. 70 mins)
  // if t1 is later in the day than t2 then you should assume t2 is on the next day

}

int main()
{
	Time t(22,0,0);
	cout << t << endl;
	cout << (t - 3600) << endl;
	cout << (t - 60) << endl;
	cout << (t - 1) << endl;
	cout << (t + 1) << endl;
}
