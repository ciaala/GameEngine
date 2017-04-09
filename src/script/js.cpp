//
// Created by crypt on 02/04/17.
//

#include <iostream>
#include "js.h"

#include "libplatform/libplatform.h"

using namespace v8;

void configure_xmlmhttp_request(v8::Isolate *pIsolate, v8::Local<v8::Context> &local) {
    
}
void configure_url_test(Isolate *isolate, Local<Context> &context) {

    Local<String> urlValue = String::NewFromUtf8(isolate, "http://ip.jsontest.com/");
    Local<String> output = String::NewFromUtf8(
            isolate, "output", NewStringType::kNormal)
            .ToLocalChecked();
    Local<String> url = String::NewFromUtf8(
            isolate, "url", NewStringType::kNormal)
            .ToLocalChecked();
    context->Global()->Set(context, output,
                           Undefined(isolate));
    context->Global()->Set(context, url, urlValue );

}

void js::say_hello_world() {

    // Initialize V8.
    V8::InitializeICUDefaultLocation("/opt/v8/out.gn/x64.release/d8");
    V8::InitializeExternalStartupData("/opt/v8/out.gn/x64.release/d8");
    Platform *platform = platform::CreateDefaultPlatform();
    V8::InitializePlatform(platform);
    V8::Initialize();

    // Create a new Isolate and make it the current one.
    Isolate::CreateParams create_params;
    create_params.array_buffer_allocator =
            v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    Isolate *isolate = Isolate::New(create_params);
    {
        Isolate::Scope isolate_scope(isolate);

        // Create a stack-allocated handle scope.
        HandleScope handle_scope(isolate);

        // Create a new context.
        Local<Context> context = Context::New(isolate);

        // Enter the context for compiling and running the hello world script.
        Context::Scope context_scope(context);



        // Create a string containing the JavaScript source code.
        Local<String> source;
        if (false) {
             source = String::NewFromUtf8(isolate, "'Hello' + ', World! I\\'m Vika Fika'",
                                        NewStringType::kNormal).ToLocalChecked();

        } else {
            const char *data =
                    "var result = undefined;\n"
                    "var isComplete = false;\n"
                    "function callback(text) {\n"
                    "    result = text;\n"
                    "    isComplete = true;\n"
                    "};\n"
                    "var xmlhttp = new XMLHttpRequest();\n"
                    "xmlhttp.onreadystatechange = function(){\n"
                    "   if (xmlhttp.readyState == 4 && xmlhttp.status == 200){\n"
                    "       callback(xmlhttp.responseText);\n"
                    "   }\n"
                    "}\n"
                    "xmlhttp.open(\"GET\", url, true);\n"
                    "xmlhttp.send();\n"
                    "while(! isComplete );\n"
                    "result";
            source = String::NewFromUtf8(
                    isolate, data, NewStringType::kNormal)
                    .ToLocalChecked();
        }
        // Compile the source code.

        std::cout << *String::Utf8Value(source) << std::endl;
        std::cout << std::flush;
        configure_xmlmhttp_request(isolate, context);
        configure_url_test(isolate, context);
        Local<Script> script = Script::Compile(context, source).ToLocalChecked();

        // Run the script to get the result.
        Local<Value> result = script->Run(context).ToLocalChecked();

        // Convert the result to an UTF8 string and print it.
        String::Utf8Value utf8(result);
        std::cout << *utf8 << std::endl;
    }

    // Dispose the isolate and tear down V8.
    isolate->Dispose();
    V8::Dispose();
    V8::ShutdownPlatform();
    delete platform;
    delete create_params.array_buffer_allocator;
}

