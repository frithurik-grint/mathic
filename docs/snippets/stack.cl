use module std::lib;
use module std::lib.io;

module Stack;

let Stack(templ T : type) <- object {
    private array : const *T;

    private index : int;
    private count : int;

    let public static .() -> Stack(T)
        = {
            .array = dim T[],
            .index = 0,
            .count = 0
        };
    
    let public static .(max) : int -> Stack(T)
        = {
            .array = dim T[max],
            .index = 0,
            .count = 0
        };

    let public push(value) : T -> ()
        = (.index < .count) ? .array[.index++] = value
                            : throw("error: index out of range");

    let public peek() -> T
        = (.index > 0) && (.index < .count) ? .array[.index - 1]
                                            : throw("error: index out of range");

    let public pop() -> T
        = (.index > 0) && (.index < .count) ? .array[--.index]
                                            : throw("error: index out of range");
};