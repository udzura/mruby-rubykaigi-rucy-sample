MRUBY_CONFIG=File.expand_path(ENV["MRUBY_CONFIG"] || ".travis_build_config.rb")
MRUBY_VERSION=ENV["MRUBY_VERSION"] || "3.0.0"

file :mruby do
  sh "git clone --depth=1 git://github.com/mruby/mruby.git"
  if MRUBY_VERSION != 'master'
    Dir.chdir 'mruby' do
      sh "git fetch --tags"
      rev = %x{git rev-parse #{MRUBY_VERSION}}
      sh "git checkout #{rev}"
    end
  end
end

file "bpf/rucy.o" => "bpf/rucy.rb" do
  rucy = ENV['RUCY'] || 'rucy'
  sh "#{rucy} object bpf/rucy.rb -d bpf/rucy.o"
end

file "src/rucy_bpf.h" => "bpf/rucy.o" do
  sh "bpftool gen skeleton bpf/rucy.o > src/rucy_bpf.h"
end

desc "compile binary"
task :compile => [:mruby, "src/rucy_bpf.h"] do
  sh "cd mruby && rake all MRUBY_CONFIG=#{MRUBY_CONFIG}"
end

desc "test"
task :test => :mruby do
  sh "cd mruby && rake all test MRUBY_CONFIG=#{MRUBY_CONFIG}"
end

desc "cleanup"
task :clean do
  exit 0 unless File.directory?('mruby')
  sh "cd mruby && rake deep_clean"
end

task :default => :compile
