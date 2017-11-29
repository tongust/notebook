# Syncing to a fork
Sync a fork of a repository to keep it up-to-date with the upstream repository.

> upstream repository: the repo of owner.
> origin repository: the repo which you self own.

## Before syncing: configuring a remote for a fork
- list the current remote repository:
> git remote -v

- Specify a new remote upstream repo:
> git remote add upstream https://github.com/ORIGINAL\_OWNER/ORIGINAL\_REPOSITORY.git

## git fetch upstream

# Configure the Git Server
## Host
### Make sure that there exits (host) id\_rsa file
If it does not, run in shell
```{shell}
ssh-keygen -t rsa -C "youremali@xxx.xx"
# Accept any default option 
```
Then, you will find two file:
- id\_rsa: private key
- id\_rsa.pub: public key

Next, append the content in id\_rsa.pub into the *authorized\_keys* file.

### Push
- git push -u origin mater : For the first time
- git push: For second time : For the second time

## Remote
### Creat git user
```{shell}
sudo git adduser git
```
### Create key
Same with *Host*'s configuration, expect that you have to create */home/git/.ssh/authorized\_keys* file.

### Deny any ssh-login
**sudo vi /etc/passwd**
Change
```
git:x:1001:1001:,,,:/home/git:/bin/bash
```
to
```
git:x:1001:1001:,,,:/home/git:/bin/bash
```

