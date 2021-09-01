# mruby-rubykaigi-rucy-sample   [![Build Status](https://travis-ci.org/udzura/mruby-rubykaigi-rucy-sample.svg?branch=master)](https://travis-ci.org/udzura/mruby-rubykaigi-rucy-sample)
RubykaigiRucySample class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'udzura/mruby-rubykaigi-rucy-sample'
end
```
## example
```ruby
p RubykaigiRucySample.hi
#=> "hi!!"
t = RubykaigiRucySample.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
