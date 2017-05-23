#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

class hugeint{
	public:
		hugeint();
		hugeint(std::string str);
		hugeint(int n);
		friend std::ostream&  operator<<(std::ostream &out, hugeint   n);
		friend std::istream&  operator>>(std::istream  &in, hugeint  &n);
		friend hugeint operator+(hugeint left, hugeint right);
		friend hugeint operator-(hugeint left, hugeint right);
		hugeint& operator=(hugeint right);

	private:
		std::vector<int> num;
		void stringtoint(const std::string &str);
		static hugeint& add(hugeint &left, const hugeint &right);
   		static hugeint& minus(hugeint &left, const hugeint &right);
};

void hugeint::stringtoint(const std::string &str){
	num.clear();
	for (int i=str.size()-1; i>=0; --i)
		num.push_back(str[i]-'0');
}

hugeint::hugeint(){
	num.push_back(0);	
}

hugeint::hugeint(std::string str){
	stringtoint(str);
}

hugeint::hugeint(int n){
	while(n){
		num.push_back(n%10);
		n /= 10;
	}
}

std::ostream& operator<<(std::ostream &out, hugeint n){
	for (int i=n.num.size()-1; i>=0; --i)
		out << n.num[i];
	return out;
}

std::istream& operator>>(std::istream &in, hugeint &n){
	std::string str;
	in >> str;
	n.stringtoint(str);
	return in;
}

hugeint operator +(hugeint left, hugeint right){
	return hugeint::add(left, right);
}

hugeint operator -(hugeint left, hugeint right){
	return hugeint::minus(left, right);
}

hugeint& hugeint::operator=(hugeint right){
    this->num = right.num;
    return *this;
}

hugeint& hugeint::add(hugeint &left, const hugeint &right){
    left.num.resize(std::max(left.num.size(), right.num.size()));
    for(int i=0;i<right.num.size();++i)
        left.num[i] += right.num[i];
    for(int i=1;i<left.num.size();++i){
        if(left.num[i-1] >= 10){
            left.num[i-1] -= 10;
            ++left.num[i];
        }
    }
    if(left.num.back() >= 10)
    {
        left.num.back() -= 10;
        left.num.push_back(1);
    }
    return left;
}

hugeint& hugeint::minus(hugeint &left, const hugeint &right){
    left.num.resize(std::max(left.num.size(), right.num.size()));
    for(int i=0;i<right.num.size();++i)
        left.num[i] -= right.num[i];
    for(int i=0, end = left.num.size()-1 ; i<end ;++i){
        if(left.num[i] < 0){
            left.num[i] += 10;
            --left.num[i+1];
        }
    }
    if(left.num.back() == 0)
        left.num.pop_back();
    return left;
}
#endif
