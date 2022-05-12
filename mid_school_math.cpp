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
  int getx(){return(x);}
  int gety(){return(y);}
  Point(int pos_x, int pos_y)
  {
	  x = pos_x;
	  y = pos_y;
  }
};


class Geometry 
{
private:
  // 점 100 개를 보관하는 배열.
  Point *point_array[100];
  int num_points;


 public:
  Geometry() 
  {
    num_points = 0;
  }

  void AddPoint(Point &point);  
  void PrintDistance();  // 모든 점들 간의 거리를 출력하는 함수 입니다.

  // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
  // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
  // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
  void PrintNumMeets(); // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
};

void Geometry:: AddPoint(Point &point)
{
	point_array[num_points++] = new Point(point.getx(), point.gety());
}

double	find_distance(Point* ar1, Point* ar2)
{
	int x1 = ar1->getx();
	int x2 = ar2->getx();
	int y1 = ar1->gety();
	int y2 = ar2->gety();
	std:: cout << "(" << x1<<", "<<y1 << ") 와 " <<"(" << x2<<", "<<y2 << ")" <<std::endl;
	int multi = (pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return(sqrt(multi));
}

void	Geometry::PrintDistance()
{
	for (int i = 0; i < num_points -1;i++)
	{
		for (int j = i + 1; j < num_points; j++)
		{
			//	std::cout << "aaaaaa\n"<<std::endl;
			double len = find_distance(point_array[i],point_array[j]);
			std::cout << i + 1 << "번째 점과 " << j + 1 << "번째 점 사이의 거리는 \n" 
				<< len <<std::endl;
		}
	}
}
//2점의 기울기를 이용해서 문제를 푸는데 두 점의 기울기의 곱이 음수이거나 0이라는건 교점이 존재한다는 의미이다. 두 직선의 기울기가 평행하지 않다면 두 직선은 반드시 교점을 가지는데 양수라는건
void	Geometry::PrintNumMeets()
{
	int gCount = 0;
	for (int i = 0; i < num_points; ++i) {
		for (int j = i + 1; j < num_points; j++) {
			for (int k = j + 1; k < num_points; k++) {
				for (int l = k + 1; l < num_points; l++) {
					if (((point_array[i]->getx()) - (point_array[j]->getx())) == 0 || ((point_array[k]->getx()) - (point_array[l]->getx())) == 0)
						continue;
					else if (((point_array[i]->gety()) - (point_array[j]->gety())) / ((point_array[i]->getx()) - (point_array[j]->getx())) * ((point_array[k]->gety()) - (point_array[l]->gety())) / ((point_array[k]->getx()) - (point_array[l]->getx())) <= 0) {
						++gCount;
					}
				}
			}
		}
	}
	std::cout << "교점의 갯수는 " << gCount << std ::endl;
}

int main()
{
	Point p1(1,1);
	Point p2(3,3);
	Point p3(2,2);
	Point p4(-1,-4);
	Geometry geo;
	geo.AddPoint(p1);
	geo.AddPoint(p2);
	geo.AddPoint(p3);
	geo.AddPoint(p4);
	geo.PrintDistance();
	geo.PrintNumMeets();
}
