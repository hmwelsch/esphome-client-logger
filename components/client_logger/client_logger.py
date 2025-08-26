import esphome.codegen as cg

CONFIG_SCHEMA = cv.Schema({})
client_logger_ns = cg.esphome_ns.namespace('client_logger')
ClientLogger = client_logger_ns.class_('ClientLogger', cg.Component)