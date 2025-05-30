# Copyright 2017 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("//bazel:grpc_build_system.bzl", "grpc_cc_binary", "grpc_cc_library", "grpc_cc_test", "grpc_package")

licenses(["notice"])

grpc_package(
    name = "test/cpp/interop",
    visibility = "public",
)

grpc_cc_library(
    name = "server_helper_lib",
    srcs = [
        "server_helper.cc",
    ],
    hdrs = [
        "server_helper.h",
    ],
    external_deps = [
        "absl/flags:flag",
    ],
    deps = [
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_binary(
    name = "grpclb_fallback_test",
    srcs = [
        "grpclb_fallback_test.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
        "absl/log:log",
        "absl/time:time",
    ],
    tags = ["no_windows"],
    deps = [
        "//:grpc++",
        "//src/proto/grpc/testing:empty_cc_proto",
        "//src/proto/grpc/testing:messages_cc_proto",
        "//src/proto/grpc/testing:test_cc_grpc",
        "//test/cpp/util:test_config",
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_binary(
    name = "interop_server",
    srcs = [
        "interop_server_bootstrap.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
    ],
    deps = [
        ":interop_server_lib",
        "//:grpc++",
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_library(
    name = "interop_server_lib",
    srcs = [
        "interop_server.cc",
    ],
    external_deps = [
        "absl/log:check",
    ],
    deps = [
        ":server_helper_lib",
        "//:grpcpp_orca_service",
        "//src/proto/grpc/testing:empty_cc_proto",
        "//src/proto/grpc/testing:messages_cc_proto",
        "//src/proto/grpc/testing:test_cc_grpc",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_library(
    name = "client_helper_lib",
    srcs = [
        "client_helper.cc",
        "interop_client.cc",
    ],
    hdrs = [
        "client_helper.h",
        "interop_client.h",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
        "absl/log:log",
    ],
    deps = [
        ":backend_metrics_lb_policy",
        "//src/proto/grpc/testing:empty_cc_proto",
        "//src/proto/grpc/testing:messages_cc_proto",
        "//src/proto/grpc/testing:test_cc_grpc",
        "//test/core/credentials/call/oauth2:oauth2_utils",
        "//test/cpp/util:test_config",
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_library(
    name = "interop_client_main",
    srcs = [
        "client.cc",
    ],
    external_deps = [
        "absl/flags:flag",
    ],
    deps = [
        ":client_helper_lib",
    ],
)

grpc_cc_binary(
    name = "interop_client",
    external_deps = ["absl/log:check"],
    deps = [
        ":interop_client_main",
        "//:grpc++",
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_binary(
    name = "metrics_client",
    srcs = ["metrics_client.cc"],
    external_deps = [
        "absl/flags:flag",
    ],
    deps = [
        "//:grpc++",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:metrics_server_lib",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_binary(
    name = "reconnect_interop_client",
    srcs = [
        "reconnect_interop_client.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
    ],
    deps = [
        ":client_helper_lib",
        "//:grpc++",
        "//test/core/test_util:grpc_test_util",
    ],
)

grpc_cc_binary(
    name = "reconnect_interop_server",
    srcs = [
        "reconnect_interop_server.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
    ],
    deps = [
        ":interop_server_lib",
        "//:grpc++",
        "//test/core/test_util:grpc_test_util",
    ],
)

grpc_cc_binary(
    name = "stress_test",
    srcs = [
        "stress_interop_client.cc",
        "stress_interop_client.h",
        "stress_test.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
        "absl/log:globals",
        "absl/log:log",
    ],
    deps = [
        ":client_helper_lib",
        "//:grpc++",
        "//test/cpp/util:metrics_server_lib",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_binary(
    name = "interop_test",
    srcs = ["interop_test.cc"],
    data = [
        ":interop_client",
        ":interop_server",
    ],
    external_deps = [
        "absl/flags:flag",
    ],
    tags = ["no_windows"],
    deps = [
        "//:gpr",
        "//:grpc",
        "//:grpc++",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
        "//test/cpp/util:test_util",
    ],
)

sh_test(
    name = "interop_test_with_metadata_log",
    srcs = [
        "interop_test_with_metadata_log.sh",
    ],
    data = [
        ":interop_test",
    ],
    tags = ["no_windows"],
)

grpc_cc_library(
    name = "xds_stats_watcher",
    srcs = ["xds_stats_watcher.cc"],
    hdrs = ["xds_stats_watcher.h"],
    external_deps = [
        "absl/log:check",
    ],
    deps = [
        ":rpc_behavior_lb_policy",
        "//:grpc++",
        "//:grpc++_reflection",
        "//:grpcpp_admin",
        "//src/proto/grpc/testing:empty_cc_proto",
        "//src/proto/grpc/testing:messages_cc_proto",
        "//src/proto/grpc/testing:test_cc_grpc",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_test(
    name = "xds_stats_watcher_test",
    srcs = [
        "xds_stats_watcher_test.cc",
    ],
    external_deps = ["gtest"],
    deps = [":xds_stats_watcher"],
)

grpc_cc_binary(
    name = "xds_interop_client",
    srcs = [
        "xds_interop_client.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
        "otel/exporters/prometheus:prometheus_exporter",
        "otel/sdk/src/metrics",
    ],
    deps = [
        ":rpc_behavior_lb_policy",
        ":xds_stats_watcher",
        "//:grpc++",
        "//:grpc++_reflection",
        "//:grpcpp_admin",
        "//:grpcpp_csm_observability",
        "//src/proto/grpc/testing:empty_cc_proto",
        "//src/proto/grpc/testing:messages_cc_proto",
        "//src/proto/grpc/testing:test_cc_grpc",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_library(
    name = "xds_interop_server_lib",
    testonly = True,
    srcs = [
        "pre_stop_hook_server.cc",
        "xds_interop_server_lib.cc",
    ],
    hdrs = [
        "pre_stop_hook_server.h",
        "xds_interop_server_lib.h",
    ],
    deps = [
        "//:grpc++",
        "//:grpc++_reflection",
        "//:grpcpp_admin",
        "//src/proto/grpc/testing:empty_cc_proto",
        "//src/proto/grpc/testing:messages_cc_proto",
        "//src/proto/grpc/testing:test_cc_grpc",
        "//test/cpp/end2end:test_health_check_service_impl",
    ],
)

grpc_cc_binary(
    name = "xds_interop_server",
    testonly = True,
    srcs = [
        "xds_interop_server.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "otel/exporters/prometheus:prometheus_exporter",
        "otel/sdk/src/metrics",
    ],
    deps = [
        ":xds_interop_server_lib",
        "//:grpc++",
        "//:grpcpp_csm_observability",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/end2end:test_health_check_service_impl",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_test(
    name = "pre_stop_hook_server_test",
    srcs = [
        "pre_stop_hook_server_test.cc",
    ],
    external_deps = ["gtest"],
    deps = [
        ":xds_interop_server_lib",
        "//:grpc++",
        "//src/proto/grpc/testing:istio_echo_cc_grpc",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_test(
    name = "xds_interop_server_test",
    srcs = [
        "xds_interop_server_test.cc",
    ],
    external_deps = ["gtest"],
    deps = [
        ":xds_interop_server_lib",
        "//:grpc++",
        "//src/proto/grpc/testing:istio_echo_cc_grpc",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_library(
    name = "istio_echo_server_lib",
    srcs = [
        "istio_echo_server_lib.cc",
    ],
    hdrs = ["istio_echo_server_lib.h"],
    deps = [
        "//:grpc++",
        "//src/proto/grpc/testing:istio_echo_cc_grpc",
    ],
)

grpc_cc_binary(
    name = "istio_echo_server",
    srcs = [
        "istio_echo_server.cc",
    ],
    external_deps = [
        "absl/flags:flag",
    ],
    deps = [
        ":istio_echo_server_lib",
        "//:grpc++",
        "//:grpc++_reflection",
        "//:grpcpp_admin",
        "//src/proto/grpc/testing:istio_echo_cc_grpc",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_test(
    name = "istio_echo_server_test",
    srcs = [
        "istio_echo_server_test.cc",
    ],
    external_deps = ["gtest"],
    deps = [
        ":istio_echo_server_lib",
        "//:grpc++",
        "//src/proto/grpc/testing:istio_echo_cc_grpc",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_binary(
    name = "http2_client",
    srcs = [
        "http2_client.cc",
        "http2_client.h",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
        "absl/log:log",
    ],
    deps = [
        "//:grpc++",
        "//src/proto/grpc/testing:empty_cc_proto",
        "//src/proto/grpc/testing:messages_cc_proto",
        "//src/proto/grpc/testing:test_cc_grpc",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_binary(
    name = "xds_federation_client",
    srcs = [
        "xds_federation_client.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "absl/log:check",
    ],
    deps = [
        ":client_helper_lib",
        "//:grpc++",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_binary(
    name = "observability_interop_server",
    srcs = [
        "observability_interop_server_bootstrap.cc",
    ],
    external_deps = [
        "absl/flags:flag",
    ],
    tags = ["nobuilder"],
    deps = [
        ":interop_server_lib",
        "//:grpc++",
        "//:grpcpp_gcp_observability",
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_library(
    name = "observability_interop_client_main",
    srcs = [
        "observability_client.cc",
    ],
    external_deps = [
        "absl/flags:flag",
        "otel/exporters/prometheus:prometheus_exporter",
        "otel/sdk/src/metrics",
    ],
    tags = [
        "nobuilder",
        # TODO(stanleycheung): the following will only work if :grpcpp_gcp_observability works
        "grpc:broken-internally",
    ],
    deps = [
        ":client_helper_lib",
        "//:grpcpp_gcp_observability",
        "//src/cpp/ext/otel:otel_plugin",
    ],
)

grpc_cc_binary(
    name = "observability_interop_client",
    tags = ["nobuilder"],
    deps = [
        ":observability_interop_client_main",
        "//:grpc++",
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_binary(
    name = "observability_interop_test",
    srcs = ["interop_test.cc"],
    data = [
        ":observability_interop_client",
        ":observability_interop_server",
    ],
    external_deps = [
        "absl/flags:flag",
    ],
    tags = [
        "no_windows",
        "nobuilder",
    ],
    deps = [
        "//:gpr",
        "//:grpc",
        "//:grpc++",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
        "//test/cpp/util:test_util",
    ],
)

grpc_cc_library(
    name = "backend_metrics_lb_policy",
    srcs = [
        "backend_metrics_lb_policy.cc",
    ],
    hdrs = [
        "backend_metrics_lb_policy.h",
    ],
    external_deps = [
        "absl/log:check",
    ],
    tags = ["nobuilder"],
    deps = [
        "//:grpc",
        "//:grpc++",
        "//src/proto/grpc/testing:messages_cc_proto",
    ],
)

grpc_cc_test(
    name = "backend_metrics_lb_policy_test",
    srcs = [
        "backend_metrics_lb_policy_test.cc",
    ],
    external_deps = ["gtest"],
    deps = [
        ":backend_metrics_lb_policy",
        "//:grpc++",
        "//:grpcpp_orca_service",
        "//src/proto/grpc/testing:test_cc_grpc",
        "//test/core/test_util:grpc_test_util",
        "//test/cpp/util:test_config",
    ],
)

grpc_cc_library(
    name = "rpc_behavior_lb_policy",
    srcs = [
        "rpc_behavior_lb_policy.cc",
    ],
    hdrs = [
        "rpc_behavior_lb_policy.h",
    ],
    external_deps = [
        "absl/log:check",
    ],
    tags = ["nobuilder"],
    deps = [
        "//:grpc",
        "//:grpc++",
    ],
)
