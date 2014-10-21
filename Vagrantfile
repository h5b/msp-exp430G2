# Vagrantfile API/syntax version. Don't touch unless you know what you're doing!
VAGRANTFILE_API_VERSION = "2"

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box = "precise32"
  config.vm.box_url = "http://files.vagrantup.com/precise32.box"

  config.vm.hostname = "msp430-dev"
  config.vm.provider "virtualbox" do |v|
    v.name = "msp430-dev"
    # Enable USB Support with EHCI and Device Filtering to support
    # msp430-Programmer
    v.customize ['modifyvm', :id, '--usb', 'on']
    v.customize ['modifyvm', :id, '--usbehci', 'on']
    v.customize ['usbfilter', 'add', '0', '--target', :id, '--name', 'msp430 Programmer', '--vendorid', '0x0451']
  end

  config.ssh.forward_agent = true

  config.vm.provision "chef_solo" do |chef|
    chef.cookbooks_path = "chef/cookbooks"
    chef.add_recipe "apt"
    chef.add_recipe "msp430"
    chef.add_recipe "msp430::vagrant"
    chef.add_recipe "etc"
  end

end
