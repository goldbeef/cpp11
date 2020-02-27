#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

class A {
public:
    // first choice
    A(const std::initializer_list<int>& v) : age(*v.begin())
    {}

    // second choice
    A(int age) : age(age)
    {}

    // third choice
    int age;
};

void f(int i) {} // chose this one
void f(const char* s) {}


int main() {
    //1. 统一初始化
    /*
    vector<int> v = { 1, 2, 3 };
    list<int> l = { 1, 2, 3 };
    set<int> s = { 1, 2, 3 };
    map<int, std::string> m = { {1, "a"}, {2, "b"} };

    A a{ 5 };
    */

    //2. 类型推导
    /*
    vector<int> vec = {1, 2, 3};
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << endl;
    }
     */

    //3. foreach
    /*
    vector<int> vec = {3, 2, 1};
    for (auto val : vec) {
        cout << val << endl;
    }

    cout << "------------" << endl;
    for (auto& val : vec) {
        cout << val << endl;
    }
    */

    //4. nullptr
    /*
    //f(NULL); //error, ambiguous
    f(nullptr);
     */

    //5. 强制枚举类型
    /*
     error for define/compare
    enum Direction {
        Left, Right
    };

    enum Answer {
        Right, Wrong
    };
     */

    /*
    enum class Direction {
        Left, Right
    };

    enum class Answer {
        Right, Wrong
    };

    auto a = Direction::Left;
    auto b = Answer::Right;
    */

    /*
     * error
    if (a == b)
        std::cout << "a == b" << std::endl;
    else
        std::cout << "a != b" << std::endl;
    */

    //6. 静态断言
    /*
    static_assert(sizeof(int) == 4);
    */

    //7. 构造函数的相互调用 delegating constructor(委托构造函数)
    /*
    class A {
    public:
        A(int x, int y, const std::string& name) : x(x), y(y), name(name) {
            if (x < 0 || y < 0)
                throw std::runtime_error("invalid coordination");
            if (name.empty())
                throw std::runtime_error("empty name");
            // other stuff
        }

        A(int x, int y) : A(x, y, "A")
        {}

        A() : A(0, 0)
        {}

    private:
        int x;
        int y;
        std::string name;
    };
     */
    return 0;
}