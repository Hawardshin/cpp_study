#include<iostream>
#include<cmath>
/*수학 관련 소프트웨어 제작 프로그램 제작
  중학생용 기하학 소프트웨어 제작필요. 2개의 클래스로 이루어짐.
  1. point : 점에 관한 정보를 다는것.
  2. geometry : 점들을 가지고 연산을 하는 클래스 
  아래의 두 클래스의 함수들을 모두 정의하라.
 */
class Point {
  int x, y;

 public:
  Point(int pos_x, int pos_y)
  {
	  x = pos_x;
	  y = pos_y;
  }
};



class Geometry {
 public:
  Geometry() 
  {
    num_points = 0;
  }

  void AddPoint(const Point &point) 
  {
    point_array[num_points ++] = new Point(point.x, point.y);
  }

  // 모든 점들 간의 거리를 출력하는 함수 입니다.
  void PrintDistance();

  // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
  // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
  // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
  // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
  void PrintNumMeets();

private:
  // 점 100 개를 보관하는 배열.
  Point* point_array[100];
  int num_points;
};

double	find_distance(Point* &ar1, Point* &ar2)
{
	return(sqrt(((ar1.x-ar2.x) * (ar1.x - ar2.x)) + ((ar1.y- ar2.y) * (ar1.y-ar2.y))));
}

void	Geometry::PrintDistance()
{
	for (int i = 0; i < num_points;i++)
	{
		for (int j = i + 1; j < num_point; j++)
		{
			double len = find_distance(point_array[i], point_array[j]);
			std::cout<<"distance" << len <<std::endl;		}
	}
}

int main()
{
	Point p1(1,1);
	Point p2(1,3);
	Point p3(2,2);
	Point p4(3,3);
	Geometry geo;
	geo.AddPoint(p1);
	geo.AddPoint(p2);
	geo.AddPoint(p3);
	geo.AddPoint(p4);
	geo.PrintDistance();
}
