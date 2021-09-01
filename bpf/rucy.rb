license! "GPL"

class SkBuff
  attr :next, :u64
  attr :prev, :u64
  # ...snip!
end

section! "kprobe/tcp_connect"
def prog(sk_buff)
  # "Detected: tcp connext may be created\n".size == 37
  bpf_trace_printk("Detected: tcp connext may be created\n", 38)
  return 0
end
