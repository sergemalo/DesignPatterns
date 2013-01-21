#include <iostream>
#include <stdint.h>
#include <vector>

namespace SM
{
  class Observer
  {
  public:
    Observer() {};
    ~Observer() {};
    Observer(Observer&) {};
    Observer& operator=(const Observer&) {};

    virtual void notify() = 0;
  };

  class Observerable
  {
  public:
    Observerable() {};  
    ~Observerable() {};
    Observerable(Observerable&) {};
    Observerable& operator=(const Observerable&) {};

    void addObserver(Observer* newObserver) {m_observers.push_back(newObserver);};

    protected:
      std::vector<Observer*> m_observers;
  };
  
  class LowLevelCalculus : public Observerable
  {
  public:
    void performOperation();
  };

  void LowLevelCalculus::performOperation()
  {
    std::cout << "Performing Operation" << std::endl;
    std::cout << "Notifying Observers..." << std::endl;
    std::vector<Observer*>::iterator it = m_observers.begin();
    while (it != m_observers.end())
    {
      (*it)->notify();
      ++it;
    }
  }

  class CalculusObserver : public Observer
  {
  public:
    void notify() {std::cout << "Notfied!" << std::endl;};
  };

};

int main(int argc, char* argv[])
{
  (argc);
  (argv);

  SM::LowLevelCalculus calc;
  SM::CalculusObserver obs1;
  SM::CalculusObserver obs2;

  calc.addObserver(&obs1);
  calc.addObserver(&obs2);

  calc.performOperation();

	return 0;
}

