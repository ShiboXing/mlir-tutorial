toy.func @add(%a: i16, %b: i16) -> i16 {
  %c = toy.add %a, %b : i16
  toy.ret %c : i16
}

// toy.func @test(%a: i32, %b: i32) -> i32 {
//   %c = toy.call @add(%a, %b) : (i32, i32) -> i32
//   toy.ret %c : i32
// }

