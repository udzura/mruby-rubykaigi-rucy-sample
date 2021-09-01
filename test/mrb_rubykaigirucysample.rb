##
## RubykaigiRucySample Test
##

assert("RubykaigiRucySample#hello") do
  t = RubykaigiRucySample.new "hello"
  assert_equal("hello", t.hello)
end

assert("RubykaigiRucySample#bye") do
  t = RubykaigiRucySample.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("RubykaigiRucySample.hi") do
  assert_equal("hi!!", RubykaigiRucySample.hi)
end
