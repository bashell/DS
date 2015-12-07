#include <iostream>
#include "queue_template.h"

int main() 
{
  Queue<int> q;
  q.push(10);
  q.push(20);
  std::cout << q.get_size() << std::endl;
  std::cout << q.top() << std::endl;
  q.pop();
  std::cout << q.get_size() << std::endl;
  if(!q.is_empty())
    std::cout << "Not empty now" << std::endl;
  q.clear();
  if(q.is_empty())
    std::cout << "Empty now" << std::endl;
  return 0;
}
