#include <jni.h>
#include <string>


//在c++文件中定义的方法一定加上 extern "C"，表示c++要兼容C，否则运行时会报错，说是native方法没有的关联的实现方法，
//但是在c文件中，就不需要 extern "C",因为本身就是c语言了，就不需要再兼容了。
//个人理解：jni时Java和C语言的交互，不是和C++的交互，如果要和c++也交互，就需要通过c作为中间人，也就是c++兼容c。
//C---》JNI---》Java   C++---->C----》-----JNI-----》Java


/*
 * JNIEXPORT ：表示是jni输出的。
 *
 * JNICALL：表示该方法是通过jni来调用的。
 *
 * Java_com_example_jianshengli_jnidemo_MainActivity_stringFromJNI 方法的命名一定要满足一定的规则，这样就可以完成静态绑定。
 * Java_包名_类名_方法名
 *
 *
 * */

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_jianshengli_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    //jobject就是该方法的关联的java的方法所属的对象，在这里就是MainActivity的实例对象。这两个参数是在调用方法的时候系统传递进来的。

    //JNIEnv *env 是一个jni环境的结构体指针变量，只要用来把c的内容变为java的内容。
    std::string hello = "Hello from C++";
    //通过JNIEnv 把c层的string变为Java层的String对象 。
    return env->NewStringUTF(hello.c_str());
}
