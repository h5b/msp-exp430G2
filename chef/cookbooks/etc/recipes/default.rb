Chef::Log.info("[Customising: /etc/motd]")
template "/etc/motd.tail" do
  source "motd.tail"
  mode "0644"
  owner "root"
  group "root"
end

Chef::Log.info("[Adding: udev Rule for msp430-USB programmer]")
template "/etc/udev/rules.d/30-mspprog.rules" do
  source "30-mspprog.rules"
  mode "0644"
  owner "root"
  group "root"
end
