/*
 * Any class field comparison test:
 */
#include <iostream>
#include <tuple>
#include <vector>
#include <utility>

using Params = std::tuple<int,std::string,float,int>;
constexpr int NumOfParams = std::tuple_size<Params>();

Params paramSet1{1,"Foo",1.7f,5};
Params paramSet2{2,"Bar",4.98f,-2};

template<typename Tuple, std::size_t... N>
auto slice_impl(Tuple& t, std::index_sequence<N...>) {
    return std::make_tuple(std::get<N>(t)...);
}

template<std::size_t N, typename Tuple>
auto slice(const Tuple& t) {
    return slice_impl(t, std::make_index_sequence<N>{});
}

template<std::size_t Idx, typename Tuple, std::size_t... N>
auto mix_impl(Tuple& t1, Tuple& t2, std::index_sequence<N...>) {
    return std::make_tuple(
        (N == Idx ? std::get<N>(t2) : std::get<N>(t1))...
    );
}

template<std::size_t Idx, typename Tuple>
auto mix(const Tuple& t1, const Tuple& t2) {
    return mix_impl<Idx>(t1,t2,std::make_index_sequence<std::tuple_size_v<Tuple>>{});
}

class Foo{
    protected:
        int i{1};
        std::string s{"Foo"};
        float f{1.7f};
        int I{5};
    public:
        Foo() = default;
        Foo(int t_i, std::string t_s = "Foo", float t_f = 1.7f, int t_I = 5)
            : i{t_i}, s{t_s}, f{t_f}, I{t_I} {}
        bool operator==(const Foo& rhs) const {
            return (i==rhs.i && s == rhs.s && f == rhs.f && I == rhs.I);
        }

        void print() const {
            std::cout <<"Foo{"<<i<<", "<<s<< ", "<<f<<", "<<I<<"}";
        }
};

template<std::size_t... Is>
std::vector<Foo> generateFoos(const Params& p, std::index_sequence<Is...>) {
    std::vector<Foo> result;
    (...,result.emplace_back(std::apply([](auto&&... args){ 
        return Foo{args...};
        },slice<Is+1>(p))));
    return result;
}

template<std::size_t... Is>
std::vector<Foo> generateFoos(const Params& p1, const Params& p2, std::index_sequence<Is...>) {
    std::vector<Foo> result;
    (...,result.emplace_back(std::apply([](auto&&... args){ 
        return Foo{args...};
        },mix<Is+1>(p1,p2))));
    return result;
}

int main() {
    
    Foo defaultFoo;

    Foo equalFoo{
        std::get<0>(paramSet1),
        std::get<1>(paramSet1),
        std::get<2>(paramSet1), 
        std::get<3>(paramSet1)
    };

    std::vector<Foo> notEqualFoos = generateFoos(paramSet2, std::make_index_sequence<NumOfParams>{});
    std::vector<Foo> ne2 = generateFoos(paramSet1, paramSet2, std::make_index_sequence<NumOfParams>{});

    notEqualFoos.insert(notEqualFoos.end(),ne2.begin(),ne2.end());

    std::cout << (defaultFoo == equalFoo) << "\n";
    
    for(auto v : notEqualFoos) {
        defaultFoo.print();
        std::cout << ( defaultFoo == v ? " equal " : " not equal ");
        v.print();
        std::cout << "\n";
    }

    // for(auto v : ne2) {
    //     defaultFoo.print();
    //     std::cout << ( defaultFoo == v ? " equal " : " not equal ");
    //     v.print();
    //     std::cout << "\n";
    // }

    return 0;
}