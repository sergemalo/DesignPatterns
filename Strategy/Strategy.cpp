#include <iostream>
#include <stdint.h>

namespace SM
{
  template <class T>
  class CachableElement
  {
  public:
    CachableElement() {};
    ~CachableElement() {};
    CachableElement(CachableElement&) {};
    CachableElement& operator=(const CachableElement&) {};

    T key() {} = 0;
  };

  class CacheStrategy
  {
  public:
    CacheStrategy() {};  
    ~CacheStrategy() {};

    private:
    CacheStrategy(CacheStrategy&);
    CacheStrategy& operator=(const CacheStrategy&);
  
  };

  template <class Strategy>
  class Cache
  {
  public:
    Cache(const uint32_t cacheSizeLocations) {};
    ~Cache() {};

    void setCacheStrategy(CacheStrategy& newStrategy);

  private:
    Cache(Cache&);
    Cache& operator=(const Cache&);
  
    Strategy        m_defaultStrategy;
    CacheStrategy&  m_masterStrategy;
  };

  class CacheStrategyLRU : public CacheStrategy
  {
  public:
    CacheStrategyLRU() {};  
    ~CacheStrategyLRU() {};

  private:
    CacheStrategyLRU(CacheStrategyLRU&);
    CacheStrategyLRU& operator=(const CacheStrategyLRU&);
  };

  class CacheClient
  {
  public:
    CacheClient();  
    ~CacheClient();

  private:
    CacheClient(CacheClient&);
    CacheClient& operator=(const CacheClient&);
  };
};

int main(int argc, char* argv[])
{
  SM::Cache<int> myCache;
  //SM::Cache<SM::CacheStrategyLRU> myCache;

  (argc);
  (argv);
	return 0;
}

