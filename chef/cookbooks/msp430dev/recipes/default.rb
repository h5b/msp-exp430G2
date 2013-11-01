Chef::Log.info("[Adding: Basic Development Packages]")
[
  "build-essential",
  "git-core",
  "vim",
].each do |p|
  package p
end

Chef::Log.info("[Adding: msp430-Toolchain Packages]")
[
  "binutils-msp430",
  "gcc-msp430",
  "gdb-msp430",
  "msp430-libc",
  "msp430mcu",
  "mspdebug",
].each do |p|
  package p
end

Chef::Log.info("[Adding: User 'vagrant' to group 'dialout']")
group "dialout" do
  action :modify
  members "vagrant"
  append true
end
