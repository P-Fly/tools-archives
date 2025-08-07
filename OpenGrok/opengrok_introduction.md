# OpenGrok Introduction

## 简介

**OpenGrok** 是一款开放源代码的快速搜索引擎 (基于JAVA)。它可以搜索、交叉引用和浏览源代码树。

## 官网

官网: https://oracle.github.io/opengrok/

Git仓库: https://github.com/oracle/opengrok

安装说明: https://github.com/oracle/opengrok/wiki/How-to-setup-OpenGrok

## 安装步骤

### 安装 JAVA

```
sudo apt install openjdk-17-jdk
```

### 安装 tomcat

 1. 下载

    ```
    wget https://downloads.apache.org/tomcat/tomcat-10/v10.1.43/bin/apache-tomcat-10.1.43.tar.gz
    ```

 2. 安装

    ```
    sudo mv apache-tomcat-10.1.43.tar.gz /opt/tomcat10
    tar -xvzf apache-tomcat-10.1.43.tar.gz
    ```

 3. 在 ~/.profile 文件中增加环境变量和服务启动

    ```
    export CATALINA_HOME=/opt/tomcat10
    if ! pgrep -f "org.apache.catalina.startup.Bootstrap" > /dev/null;
    then
        /opt/tomcat10/bin/startup.sh > /dev/null
    fi
    ```

 5. 部署opengrok

    ```
    cp ~/opengrok/dist/lib/source.war /opt/tomcat10/webapps/
    ```

 6. 修改 /opt/tomcat10/webapps/source/WEB-INF/web.xml 中的配置

    ```
    <param-name>CONFIGURATION</param-name>
    <param-value>/home/pengfei24/opengrok/etc/configuration.xml</param-value>
    ```

### 安装 universal-ctags

```
sudo snap install universal-ctags
sudo update-alternatives --install /usr/bin/ctags ctags /snap/bin/ctags 3
sudo update-alternatives --config ctags
```

系统默认的 **apt install universal-ctags** 版本较低，不一定适用。因此使用 **snop** 下载最新的稳定版，并使用 **update-alternatives** 配置为当前使用的版本。

### 安装 OpenGrok

 1. 下载

    ```
    wget https://github.com/oracle/opengrok/releases/download/1.14.1/opengrok-1.14.1.tar.gz
    ```

 2. 创建目录

    ```
    mkdir ~/opengrok/src    # 需要分析的代码，建议用软链接管理
    mkdir ~/opengrok/data   # 存储代码的分析数据
    mkdir ~/opengrok/dist   # 存放下载的opengrok镜像
    mkdir ~/opengrok/etc    # 配置信息
    mkdir ~/opengrok/log    # 日志文件
    ```

 3. 解压

    ```
    tar -C ~/opengrok/dist --strip-components=1 -zxf opengrok-1.14.1.tar.gz
    ```

 4. 配置日志信息

    ```
    cp ~/opengrok/dist/doc/logging.properties ~/opengrok/etc
    将配置文件中的 java.util.logging.FileHandler.pattern 配置为目录 ~/opengrok/log
    ```

 5. 安装管理工具

    ```
    apt install python3.10-venv
    cd ~/opengrok/dist/tools/
    python3 -m venv env
    . ./env/bin/activate
    python3 -m pip install opengrok-tools.tar.gz
    ```

 6. 为项目工程建立软链接

    ```
    cd ~/opengrok/src
    ln -s ~/workspace/linux/ linux
    ```

 7. 创建代码索引

    ```
    java \
        -Djava.util.logging.config.file=/home/pengfei24/opengrok/etc/logging.properties \
        -jar /home/pengfei24/opengrok/dist/lib/opengrok.jar \
        -c /usr/bin/ctags \
        -s /home/pengfei24/opengrok/src -d /home/pengfei24/opengrok/data -H -P -S -G \
        -W /home/pengfei24/opengrok/etc/configuration.xml -U http://localhost:8080/source
    ```
