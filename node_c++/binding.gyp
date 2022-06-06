{
  "targets": [
    {
      "target_name": "addon",
      'cflags!': [ '-fno-exceptions' ],
	    'cflags_cc!': [ '-fno-exceptions' ],
	    'xcode_settings': {
		    'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
		    'CLANG_CXX_LIBRARY': 'libc++',
		    'MACOSX_DEPLOYMENT_TARGET': '10.7',
	    },
	    'msvs_settings': {
		    'VCCLCompilerTool': { 'ExceptionHandling': 1 },
	    },
      "sources": [ 
        "./addon.cc",
        "./demo/demo.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'conditions': [
        [
          'OS=="win"',{
            "include_dirs": [ "./testDLL/"],
            'libraries': ["testDLL.lib"],
            'library_dirs': ['./testdll/']
          }
        ],
        [
          'OS=="mac"',{
            
          }
        ]
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    },
    {
      "target_name": "copy_binary",
      "type":"none",
      "dependencies" : [ "addon" ],
      "copies":[
        {
           'destination': './third_party/',
           'files': ['./build/Release/addon.node']
        }
      ]
    }
  ]
}