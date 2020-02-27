#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <functional>

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

constexpr int GetSize() { return 3; }

void print(const std::vector<int>& data, std::function<bool(int)> filter) {
    for (auto i : data) {
        if (filter(i))
            std::cout << i << std::endl;
    }
}

//testmain

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

    //8.禁止重写final
    /*
    class A {
    public:
        virtual void f1() final {}
    };

    class B : public A {
        virtual void f1() {} //error
    };
     */

    /*
    class A final {
    };

    class B : public A { //error
    };
     */

    //9. 显示override
    /*
    class A {
    public:
        virtual void f1() const {}
    };

    class B : public A {
        //virtual void f1() override {} //error
        virtual void f1() const override {} //error
    };
     */

    //10.定义成员默认值
    /*
    class M {
    public:
        M(int i) : i(i) {
            std::cout << "M(" << i << ")" << std::endl;
        }

        M(const M& other) : i(other.i) {
            std::cout << "copy M(" << i << ")" << std::endl;
        }

        M& operator = (const M& other) {
            i = other.i;
            std::cout << "= M(" << i << ")" << std::endl;
            return *this;
        }

    private:
        int i;
    };

    class A {
    public:
        A() : m(1)
        {}

    private:
        M m = M(2); //ignored
    };

    A a;
     */

    //11. 默认构造函数 default
    /*
    class A {
    public:
        A(int i) {}
        A() = default;
    };
     */

    //12. 删除构造函数 delete
    /*
    class A {
    public:
        A() = delete;
    };
     */

    //13. 常量表达式 constexpr
    //int b[GetSize()];

    //14. 字符串字面量
    /*
    const char* e = R"(string e1 "\\
    stirng e2)";                    // raw string
    cout << e << endl;
    */

    //15. lambda表达式
    /*
    auto add = [](int a, int b)  { return a + b; };
    std::cout << add(1, 2) << std::endl;
    */

    std::vector<int> v = { 5, 10, 15, 20 };
    print(v, [](int i) { return i > 10; });     // 输出 15 20
    return 0;
}