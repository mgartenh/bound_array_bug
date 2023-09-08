#include "bound.decl.h"

using namespace std;

CProxy_Bound boundProxy;
CProxy_A aProxy;
CProxy_B bProxy;

class Bound : public CBase_Bound {
    private:
    public:
        Bound(CkArgMsg* m) {
            boundProxy = thisProxy;
            aProxy=CProxy_A::ckNew(2);
            CkArrayOptions opts(2);
            opts.bindTo(aProxy);
            bProxy=CProxy_B::ckNew(opts);
        }
};

class A: public CBase_A {
    public:
        A() {
        };
};

class B: public CBase_B {
    public:
        B() {
        };
};


#include "bound.def.h"