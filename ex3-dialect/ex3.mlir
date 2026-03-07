func.func @test(%a: i16, %b: i16) -> i16 {
  %c = "toy.add"(%a, %b): (i16, i16) -> i16
  func.return %c : i16
}