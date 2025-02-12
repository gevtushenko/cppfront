
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-types-inheritance.cpp2"

#line 2 "pure2-types-inheritance.cpp2"
class Human;
    

#line 6 "pure2-types-inheritance.cpp2"
namespace N {
    template<int I> class Machine;
        

#line 11 "pure2-types-inheritance.cpp2"
}

class Cyborg;


//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-types-inheritance.cpp2"

#line 2 "pure2-types-inheritance.cpp2"
class Human {
    public: virtual auto speak() const -> void = 0;
    public: virtual ~Human() noexcept;

    public: Human() = default;
    public: Human(Human const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(Human const&) -> void = delete;

#line 4 "pure2-types-inheritance.cpp2"
};

namespace N {
    template<int I> class Machine {
        public: explicit Machine([[maybe_unused]] cpp2::in<std::string> unnamed_param_2);
        public: virtual auto work() const -> void = 0;
        public: virtual ~Machine() noexcept;

        public: Machine(Machine const&) = delete; /* No 'that' constructor, suppress copy */
        public: auto operator=(Machine const&) -> void = delete;

#line 10 "pure2-types-inheritance.cpp2"
    };
}

struct Cyborg_name_as_base { std::string name; };
struct Cyborg_address_as_base { std::string address; };
#line 13 "pure2-types-inheritance.cpp2"
class Cyborg: public Cyborg_name_as_base, public Human, public Cyborg_address_as_base, public N::Machine<99> {

#line 19 "pure2-types-inheritance.cpp2"
    public: explicit Cyborg(cpp2::in<std::string> n);

#line 25 "pure2-types-inheritance.cpp2"
    public: auto speak() const -> void override;

#line 28 "pure2-types-inheritance.cpp2"
    public: auto work() const -> void override;

#line 31 "pure2-types-inheritance.cpp2"
    public: auto print() const& -> void;

#line 34 "pure2-types-inheritance.cpp2"
    public: ~Cyborg() noexcept;
    public: Cyborg(Cyborg const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(Cyborg const&) -> void = delete;


#line 36 "pure2-types-inheritance.cpp2"
};

auto make_speak(cpp2::in<Human> h) -> void;

#line 43 "pure2-types-inheritance.cpp2"
auto do_work(cpp2::in<N::Machine<99>> m) -> void;

#line 48 "pure2-types-inheritance.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-types-inheritance.cpp2"


Human::~Human() noexcept{}
#line 6 "pure2-types-inheritance.cpp2"
namespace N {

        template <int I> Machine<I>::Machine([[maybe_unused]] cpp2::in<std::string> unnamed_param_2){}

        template <int I> Machine<I>::~Machine() noexcept{}

#line 11 "pure2-types-inheritance.cpp2"
}

#line 19 "pure2-types-inheritance.cpp2"
    Cyborg::Cyborg(cpp2::in<std::string> n)
        : Cyborg_name_as_base{ n }
        , Human{  }
        , Cyborg_address_as_base{ "123 Main St." }
        , N::Machine<99>{ "Acme Corp. engineer tech" }{

#line 22 "pure2-types-inheritance.cpp2"
        std::cout << cpp2::to_string(name) + " checks in for the day's shift\n";
    }

    auto Cyborg::speak() const -> void { 
        std::cout << cpp2::to_string(name) + " cracks a few jokes with a coworker\n";  }

    auto Cyborg::work() const -> void { 
        std::cout << cpp2::to_string(name) + " carries some half-tonne crates of Fe2O3 to cold storage\n";  }

    auto Cyborg::print() const& -> void { 
        std::cout << "printing: " + cpp2::to_string(name) + " lives at " + cpp2::to_string(address) + "\n";  }

    Cyborg::~Cyborg() noexcept { 
        std::cout << "Tired but satisfied after another successful day, " + cpp2::to_string(name) + " checks out and goes home to their family\n";  }

#line 38 "pure2-types-inheritance.cpp2"
auto make_speak(cpp2::in<Human> h) -> void{
    std::cout << "-> [vcall: make_speak] ";
    CPP2_UFCS_0(speak, h);
}

auto do_work(cpp2::in<N::Machine<99>> m) -> void{
    std::cout << "-> [vcall: do_work] ";
    CPP2_UFCS_0(work, m);
}

auto main() -> int{
    Cyborg c {"Parsnip"}; 
    CPP2_UFCS_0(print, c);
    CPP2_UFCS_0(make_speak, c);
    CPP2_UFCS_0(do_work, std::move(c));
}

