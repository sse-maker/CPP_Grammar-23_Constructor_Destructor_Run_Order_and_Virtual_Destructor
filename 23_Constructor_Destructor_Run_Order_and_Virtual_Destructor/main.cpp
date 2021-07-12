//
//  main.cpp
//  23_Constructor_Destructor_Run_Order_and_Virtual_Destructor
//
//  Created by 세광 on 2021/07/12.
//

#include <iostream>

using namespace std;

class Ice {
public:
    Ice() { cout << "Ice()" << endl; }
    ~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
public:
    Pat() { cout << "Pat()" << endl; }
    ~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
public:
    Bingsoo() {
        cout << "Bingsoo()" << endl;
        ice = new Ice; // ice 타입을 가진 객체 생성 (Ice에 있는 생성자가 호출됨)
    }
    virtual ~Bingsoo() {
        cout << "~Bingsoo()" << endl;
        delete ice;
    }
    
private:
    Ice *ice;
    // Ice에 있는 생성자가 호출되지 않음 (Ice 타입의 객체가 아닌 포인터)
    // 포인터 자체가 만들어지는 것은 맞음 (동적 할당이 되어 있는 경우에도 멤버가 먼저 생성되는 것은 동일)
};

class PatBingsoo : public Bingsoo {
public:
    PatBingsoo() {
        cout << "PatBingsoo()" << endl;
        pat = new Pat;
    }
    ~PatBingsoo() {
        cout << "~PatBingsoo()" << endl;
        delete pat;
    }
    
private:
    Pat *pat;
};

int main() {
    // PatBingsoo *p = new PatBingsoo;
    // Bingsoo *p = new Bingsoo;
    Bingsoo *p = new PatBingsoo;
    delete p;
}
// 자식 class의 생성자가 호출되면 부모 class에 있는 기본 생성자 호출
// 생성자의 역할: 멤버들을 초기화하는 것 -> 멤버들을 먼저 만들어야 생성자를 호출할 수 있음
// 멤버들을 삭제하기 이전에 소멸자를 호춣하여 소멸자에서 해야 할 작업을 먼저 수행 (ex. 메모리 해제) (파생된 것을 먼저 삭제한 다음에 기본적인 것을 삭제하는 원리)
// 소멸자의 경우 웬만하면 가상으로 설정하는 것이 좋음
