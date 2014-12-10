Chef::Log.info("[Customising: /etc/motd]")
template "/etc/update-motd.d/99-banner" do
  source "motd.ascii.banner"
  mode "0755"
  owner "root"
  group "root"
  action :create_if_missing
end
