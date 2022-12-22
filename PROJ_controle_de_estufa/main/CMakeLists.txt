idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "."
                    REQUIRES dht nvs_flash esp-tls esp_http_server protocol_examples_common ldr_lux)
