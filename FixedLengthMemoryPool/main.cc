#include"ObjectPool.h"


void Test()
{
  ObjectPool<int> pool;
  int* p1 = pool.New();
  int* p2 = pool.New();

  cout<<p1<<endl;
  cout<<p2<<endl;

  pool.Delete(p1);
  pool.Delete(p2);

  cout<<pool.New()<<endl;
  cout<<pool.New()<<endl;
}

int main()
{
  Test();
}
