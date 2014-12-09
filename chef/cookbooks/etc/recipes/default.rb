Chef::Log.info("[Customising: /etc/motd]")
template "/etc/motd.tail" do
  source "motd.tail"
  mode "0644"
  owner "root"
  group "root"
  action :create_if_missing
end
