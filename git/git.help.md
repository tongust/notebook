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
## Init a project
Create a git in remote server.
>cd /srv/

>sudo git init --bare sample.git

>sudo chown -R git:git sample.git

# [Show changes as Git Gui](https://stackoverflow.com/questions/1587846/how-do-i-show-the-changes-which-have-been-staged)
![A simple graphic](./figures/graphic-git-diff.png)
## git diff
Shows the changes between the working directory and the index. This shows what has been changed, but is not staged for a commit.

## git diff --cached
Shows the changes between the index and the *HEAD* (which is the last commit on this branch). This shows what has been added to the index and staged for a commit.

## git diff *HEAD*
Shows all the changes between the working directory and *HEAD* (which includes changes in the index). This shows all the changes since the last commit, whether or not they have been staged for commit or not.
