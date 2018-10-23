---
title: School exercise environment
layout: main
---

The goal of this step is for you to get confident with the ESC working
environment and check that everything is correctly set up for the
school exercises.

If something doesn't work as expected, please ask one of the
organizers.

When using these computing resources you agree to comply with the "Acceptable
Use Policy" of INFN-CNAF, available
in [Italian](https://www.cnaf.infn.it/wp-content/uploads/2016/10/AUP_it.pdf)
and [English](https://www.cnaf.infn.it/wp-content/uploads/2016/10/AUP_en.pdf)

## Wi-Fi access

Make sure you are using the INFN-Captive WiFi or eduroam networks and
not the CEUB WiFi network. Only the INFN-Captive or eduroam networks
will allow to connect to the ESC computers.

## SSH access to school computers

You have been assigned a personal account, with a username of the form
`studentNM`, where `NM` is a number between 01 and 20. In the following,
when you see `student`, replace it with your personal account. You
should also have received the corresponding password.

To log on the computers prepared for the School, you have to go first through a
gateway, named `bastion.cnaf.infn.it`, with the username and password of
`student`.

	[me@mylaptop ~]$ ssh -XA student@bastion.cnaf.infn.it
	student@bastion.cnaf.infn.it's password:
	Last login: ...
	[student@bastion ~]$

The `-X` option forwards the X11 display. The `-A` option forwards the SSH agent.

From `bastion` you can then log onto the School computer assigned to you. The computer is named
`hpc-200-06-0X.cr.cnaf.infn.it`, where `X` is a number between 5 and 8. The name
is awful, we know, but you can get around it by creating a config file for ssh on
the `bastion` host:

	[student@bastion ~]$ cat .ssh/config
    ForwardX11 yes
    ForwardAgent yes

    Host esc
    Hostname hpc-200-06-0X.cr.cnaf.infn.it
    [student@bastion ~]$ ssh esc
    student@hcp-200-06-0X.cr.cnaf.infn.it's password:
    Last login: ...
	[student@hcp-200-06-0X ~]$

Remember to replace the `X` with the number assigned to you.

In the following, when you see `esc`, it means the name of the machine assigned to you.

To simplify the login from `bastion` to `esc`, you may create an SSH key on `bastion` and register it on `esc`:

	[student@bastion ~]$ ssh-keygen
    Generating public/private rsa key pair.
    Enter file in which to save the key (/home/HPC/student/.ssh/id_rsa):
    Enter passphrase (empty for no passphrase):
    Enter same passphrase again:
    ...
	[student@bastion ~]$ ssh-copy-id esc
    ...
    [student@bastion ~]$ ssh esc
	Last login: ...
	[student@hpc-200-06-0X ~]$

Your shell is [`bash`](http://www.gnu.org/s/bash).

Please note that:
* the `bastion` host is useful and needed only as a gateway to `esc`
* each `esc` computer is not assigned exclusively to a student
* the home directory is shared between all `esc` computers, but not with `bastion`
* your home directory will be wiped out and your `student` account will be
  disabled soon after the end of the School. Please make sure to save somewhere
  else what you want to keep.

## School material

All the school material is included in a git repository. Get it using:

    [student@esc ~]$ git clone https://github.com/infn-esc/esc18.git

## Testing the environment

1. Log into `esc`.

1. Enable the right toolsets

       [student@esc ~]$ scl enable devtoolset-7 llvm-toolset-7 bash

1. Check the following commands and the respective outputs.

       [student@esc ~]$ gcc --version
       gcc (GCC) 7.3.1 20180303 (Red Hat 7.3.1-5)
       ...
       [student@esc ~]$ clang --version
       clang version 5.0.1 (tags/RELEASE_501/final)
       ...
       [student@esc ~]$ valgrind --version
       valgrind-3.13.0
       [student@esc ~]$ perf --version
       perf version 3.10.0-693.21.1.el7.x86_64.debug

## Editing source code

### Editing locally

On `esc` you can find several editors available, such as vim, emacs, nano. If
the X display is available, graphical editors will open a window on your laptop;
the network latency however may not be good enough to give you a fine
experience. Just try.

### Editing remotely

Alternatively you could edit the source code for the exercises on your laptop,
synchronizing the files with the `esc` machine, for example using one of the
following:

* `scp`: You can copy files remotely using `scp`, in both directions.

* `sshfs`: You can mount your `esc` home directory on your laptop via `sshfs`.

* `rsync`: You can synchronize your local workspace with the one you keep on `esc`
  using [`rsync`](http://rsync.samba.org/). Please refer to the `rsync` manual to
  fully understand the meaning of the different options, so to avoid mistakes
  that could cause loss of data.

For this to work seamlessly, however, you should first simplify your use of SSH
to connect to `esc`, namely:

* enable the use of SSH keys in place of password authentication also from your
  laptop to `bastion`
* enable an SSH tunnel on `bastion` in order to be able to connect directly from
  your laptop to `esc`

The setup is not overly difficult, but it's not trivial either, so we suggest
this approach only if you are familiar with the SSH mechanisms.
