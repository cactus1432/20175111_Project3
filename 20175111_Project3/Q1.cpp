#include <iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z }{}

	Vector operator+(const Vector& v) const //const는 실제로 값을 변화시키지 않을때
	{
		return Vector{ x + v.x,y + v.y,z + v.z };
	}
	Vector operator-()const
	{
		return Vector{ -x,-y,-z };
	}
	float operator*(const Vector& v)const
	{
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}
	Vector operator*(float n)const
	{
		return Vector{ x * n,y * n,z * n };
	}
	Vector& operator++() //값을 변화해야 하기 때문에 const는 사용안함
	{
		x++;
		y++;
		z++;
		return *this;
	}
	Vector& operator++(int) //후위증감연산은 괄호안에 자료타입 삽입(종류무관)
	{
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;
	}
	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}
};

int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v2 = v0 + v1;
	v2.print();
	Vector v3 = -v1;
	v3.print();
	float v4 = v0 * v1; //내적계산
	cout << v4 << endl;
	Vector v5 = v1 * 3.0f;
	v5.print();
	Vector v6 = ++v1;
	v6.print();
	Vector v7 = v1++;
	v7.print();
	v1.print();
}