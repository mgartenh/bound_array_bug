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
	    //aProxy.aMethod();
	}
};

class A: public CBase_A {
    public:
        A() {
            //bProxy[thisIndex].ckLocal();
            if(thisIndex==1) migrateMe(0);
	    else migrateMe(0);
	};
        void aMethod() {
	    //if(thisIndex==1) migrateMe(0);
	    //else migrateMe(0);
	    //if(thisIndex==0)
	    //B* ptr = bProxy[thisIndex].ckLocal();
	    if(thisIndex==0) B* ptr = bProxy[1].ckLocal();
	    else B* ptr = bProxy[0].ckLocal();
	}
	A(CkMigrateMessage *m){}
};

class B: public CBase_B {
    public:
        B() {
            aProxy[thisIndex].ckLocal() -> aMethod();
	    //A* ptr = aProxy[thisIndex].ckLocal();
	};
	B(CkMigrateMessage *m) {}
};


#include "bound.def.h"
