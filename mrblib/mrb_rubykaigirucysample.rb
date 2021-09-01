def __main__(_)
  bpf = BPF.new
  bpf.attach

  tracer = File.open "/sys/kernel/debug/tracing/trace_pipe"
  while l = tracer.readline
    puts l
  end
end
