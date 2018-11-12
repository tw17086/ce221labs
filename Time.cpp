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
	if (hour != t.hour) return hour < t.hour;
	else if (min != t.min) return min < t.min;
	else return sec < t.sec;
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
	min -= abs(sec)/60;
	hour -= abs(min)/60;

	sec %= 60;
	min %= 60;
	hour %= 24;

	if (sec < 0)
	{	sec += 60;
		min -= 1;
	}
	if (min < 0)
	{	min += 60;
		hour -= 1;
	}
	if (hour < 0) hour += 24;
	return *this;
}

Time& Time::operator--()// prefix version
{	*this -= 1;
  	return *this;
}

Time Time::operator--(int)// postfix version
{	Time tCopy(*this);
	*this -= 1;
  	return tCopy;
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
	return !(t1 < t2);
}
bool operator!=(const Time& t1, const Time& t2){
	return !(t1 == t2);
}
unsigned int operator%(const Time& t1, const Time& t2){
  // t1%t2 should mean the elapsed time in sec from t1 to t2
  // e.g. if t1 is 10.45am and t2 is 11.55am t1%t2 would be 4200 (i.e. 70 mins)
  // if t1 is later in the day than t2 then you should assume t2 is on the next day

  if (t2 >= t1){ return ((t2.hour-t1.hour)*3600 + (t2.min-t1.min)*60 + t2.sec-t1.sec);}
  else { return (24*60*60 - ((t1.hour-t2.hour)*3600 + (t1.min-t2.min)*60 + t1.sec-t2.sec)); }


}

int main()
{
	Time t(22,33,22);
	cout << t << endl;
	cout << (t - 2430) << endl << (t--) << endl << (--t) << endl;
	Time t2(12,34,56);
	cout << (t != t2) << endl;
	cout << (t < t2) << endl;
	cout << (t2 >= t) << endl;
	cout << (t >= t2) << endl;
	cout << (t2%t) << "		" << (t%t2) << endl;
	cout << (Time() + t2%t) << "	 " << (Time() + t%t2) << endl;
	cout << (Time(10,45)%Time(11,55)) << endl;
	cout << (Time() + Time(10,45)%Time(11,55)) << endl;
}
